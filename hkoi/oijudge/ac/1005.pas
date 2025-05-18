program p1005;
var
	i,j,k,n : longint;
	w : array[1..100000] of char;
	c : char;
begin
	n := 0;
	while not eoln do begin
		inc(n);
		read(c);
		w[n] := c;
	end;
	readln;
	n := n - 4;
	for i := 1 to n div 2 do begin
		c := w[i];
		w[i] := w[n-i+1];
		w[n-i+1] := c;
	end;

	for i := 1 to n do write(w[i]); writeln('.mp3');
end.
