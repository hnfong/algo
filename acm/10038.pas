program JollyJumpers;
var
	a : array[0..3000] of Boolean;
	m, n, t  : longint;
	i, j, k : longint;
begin
	while not eof do
	begin
		fillchar(a,sizeof(a),0);
		read(k);
		read(n);
		if (k = 1) then
		begin
			writeln('Jolly');
			readln;
			continue;
		end;
		for i := 2 to k do
		begin
			m := n;
			read(n);
			t := abs(m - n);
			if (t = 0) or (t > k-1) or (a[t mod 3000]) then
			begin
				writeln('Not jolly');
				for j := i + 1 to k do
					read(n);
				readln;
				break;
			end;
			a[t] := TRUE;
		end;
		if (i = k) then
			writeln('Jolly');
	end;
end.
