program p5021;
var
	i,j,k : longint;
	v,t : double;
	d : array[1..3] of double;
	unknown : longint;

function eval3 : longint;
var
	i,j,k : longint;
	z,t : double;
	canfail : boolean;
	canpass : boolean;
begin
	{ all known }
	if (unknown = 0) then begin
		z := d[1]+d[2]+d[3];
		if z > 220 then eval3 := -1 else eval3 := 1;
		exit;
	end;
	
	{ try to fail the test }
	canfail := false;

	if (unknown = 2) then begin
		z := d[1] + 10 + v/d[1]/10;
		if z > 220 then canfail := true;
	end;
	if (unknown = 3) then begin
		if v >= 10*10*200 then canfail := true;
	end;

	{ now try to pass it }
	canpass := false;
	if (unknown = 2) then begin
		z := d[1] + sqrt(v/d[1])*2;
		if z <= 220 then canpass := true;
	end;
	if (unknown = 3) then begin
		if v <= power(220/3,3.0) then canpass := true;
	end;

	if canpass and canfail then eval3 := 0;
	if canpass and not canfail then eval3 := 1;
	if not canpass and canfail then eval3 := -1;
	if not canpass and not canfail then while true do;
end;


function eval4 : longint;
var i,j : longint;
canfail, canpass : boolean;
begin
	{ check all of them first }
	eval4 := -1;
	for i := 1 to 3 do begin
		if d[i] > 130 then exit;
	end;
	
	{ if no unknowns, i.e. all checked }
	if unknown = 0 then begin
		eval4 := 1;
		exit;
	end;

	{ try to fail it }
	canfail := false;
	if unknown = 2 then begin
		if v/d[1]/10 > 130 then canfail := true;
	end;
	if unknown = 3 then begin
		if v/10/10 > 130 then canfail := true;
	end;

	{ try to pass it }
	canpass := false;
	if unknown = 2 then begin
		if v/d[1] <= sqr(130) then canpass := true;
	end;
	if unknown = 3 then begin
		if v <= 130*130*130 then canpass := true;
	end;
	
	if canpass and canfail then eval4 := 0;
	if canpass and not canfail then eval4 := 1;
	if not canpass and canfail then eval4 := -1;
	if not canpass and not canfail then while true do;
end;


begin
	readln(v, d[1] ,d[2],d[3]);
	unknown := 0;
	for i := 1 to 3 do
		if d[i] = -1 then inc(unknown); 

	{ if only 1 unknown then find it out }
	if unknown = 1 then begin
		if d[1] = -1 then d[1] := v/d[2]/d[3];
		if d[2] = -1 then d[2] := v/d[1]/d[3];
		if d[3] = -1 then d[3] := v/d[2]/d[1];
		unknown := 0;
	end;

	{ sort it to get the unknowns out of the way }
	for i := 1 to 3 do begin
		for j := i downto 2 do begin
			if d[j]>d[j-1] then begin
				t := d[j];
				d[j] := d[j-1];
				d[j-1] := t;
			end;
		end;
	end;
	if (eval3 = 1) and (eval4 = 1) then begin
		writeln('Carry it on board!');
		exit;
	end;
	if (eval3 = -1) or (eval4 = -1) then begin
		writeln('Pay for consignment!');
		exit;
	end;
	if (eval3 = 0) or (eval4 = 0) then begin
		writeln('Not sure!');
		exit;
	end;
end.

