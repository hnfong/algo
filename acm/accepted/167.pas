program x167;
{
	@JUDGE_ID:  20044WC 167 PASCAL "Siliconism"
}
var
	a : array [1..8] of longint;
	h,i,j,k : longint;
	map : array[1..100, 1..8,1..8] of byte;
	nummaps : longint;
	n : longint;
	data : array[1..8,1..8] of byte;
	ac : longint;
	max : longint;
procedure dump;
var
	i,j,k : longint;
begin
	for k := 1 to nummaps do begin
		for j := 1 to 8 do begin
			for i := 1 to 8 do
				write(map[k,i,j]);
			writeln;
		end;
		writeln;
	end;
end;

procedure dumpmap(x : longint);
var i,j : longint;
begin
	for i := 1 to 8 do begin
		for j := 1 to 8 do begin
			if a[i] = j then map[x, j,i] := 1 else map[x, j,i] := 0;
		end;
	end;
end;

procedure put(l : longint);
var
	i,j,k : longint;
	t : boolean;
begin
{	dump;}
	if (l > 8) then begin
		inc(nummaps);
		dumpmap(nummaps);
		exit;
	end;
	for i := 1 to 8 do begin
		t := true;
		{ check vertical clash }
		for j := 1 to 8 do begin
			if (a[j] = i) then t := false;
		end;
		if (t = false) then continue;
		{ check diagonal clash }
		for j := 1 to l-1 do begin
			{ this is slope }
			if (abs(abs((j - l) / (a[j] - i)) - 1) < 0.00001) then  t:= false;
		end;
		if t = true then begin 
			a[l] := i;
			put(l + 1);
			a[l] := 0;
		end;
	end;
end;

begin
	{ preparation }
	nummaps := 0;
	put (1);
	{ do the real processing }
	
	readln(n);
	for h := 1 to n do begin
			for i := 1 to 8 do begin
			for j := 1 to 8 do begin
				read(data[j,i]);
			end;
			readln;
		end;
		
		max := 0;
		for k := 1 to nummaps do begin
			ac := 0;
			for j := 1 to 8 do begin
				for i := 1 to 8 do begin
					ac := ac + data[i,j] * map[k,i,j];
				end;
			end;
			if (max < ac) then max := ac;
		end;
		writeln(max:5);
	end;
end.

