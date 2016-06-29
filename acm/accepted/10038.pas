program p10038;
{
@JUDGE_ID:  20044WC 10038 PASCAL "Dun Inch Me!!!"
}
var
	i : longint;
	n : longint;
	a,b : longint;
	z : array[0..4000] of byte;
	j : boolean;
begin
	while not eof do begin
		fillchar(z,sizeof(z),0);
		read(n);
		read(a);
		for i := 1 to n-1 do begin
			read(b);
			if abs(a-b) < 3000 then z[abs(a-b)] := 1;
			a := b;
		end;
		j := true;
		for i := 1 to n-1 do begin
			if z[i] = 0 then begin
				j := false;
				break;
			end;
		end;
		readln;
		if j then writeln('Jolly') else writeln('Not jolly');
	end;
end.
