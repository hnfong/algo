program plamps;
var
	i,j,k,n : longint;
{ to be refined }
function getz(x:longint) : longint;
begin
	getz := round(power(2, trunc ( ln(x-1) / ln(2) )+1));
end;
function find(x,y,z,w: longint) : boolean;
var k : longint;
begin
	if (y > z) then begin
		x := (x-(w-z)-1+z) mod z + 1;
		y := (y+(w-z)-1+z) mod z + 1;
		find := find(x,y,z,w);
		exit;
	end;
	if z = 1 then begin find := true; exit; end;
	k := z div 2;
	if (x <= k) and (y <= k) then begin find := false; exit; end;
	if x > k then x := x - k;
	if y > k then y := y - k;
	find := find(x,y,k,w);
end;

begin
	for j := 1 to 200 do begin
		for i := 1 to 64 do begin
			if find(i,j, 64, 66) then write('#') else write('.');
		end;writeln(' ',j);
	end;
end.
