program p1006;
var
	i,j,k : longint;
	n : longint;
	z : longint;
begin
	readln(z);
	z := -z;
	readln(n);
	for i := 1 to n do begin
		readln(k);
		z := z + k;
	end;
	k := 0;
	k := z - z mod 250;
	if z >= 0 then k := k + 250;
	if k < 0 then k := 0;
	writeln('$', k);
end.
