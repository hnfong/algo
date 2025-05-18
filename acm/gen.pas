program gen;
var
	i,j, k,a: longint;
begin
	a := random(50)+1;
	j := a;
	for i := 1 to 999 do begin
		k := random(50)+1;
		writeln(j,' ', k);
		j := k;
	end;
	writeln(k,' ',a);
end.
