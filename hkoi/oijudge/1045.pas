var
	i,j,k,n : longint;
	w : array[1..100,1..100] of longint;
begin
	readln(n);
	for i := 1 to n do begin
		for j := 1 to n do
			read(w[i,j]);
		readln;
	end;
	for k := 1 to n do
		for i := 1 to n do
			for j := 1 to n do
				w[i,j] := w[i,j]+w[i,k]*w[k,j];
	for i := 1 to n do begin
		for j := 1 to n-1 do
			write(w[i,j], ' ');
		writeln(w[i,n]);
	end;
end.
