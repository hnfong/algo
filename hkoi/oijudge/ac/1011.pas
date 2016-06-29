program p1011;
var
	i,j,k,n,ni : longint;
	x1,x2,y1,y2 : longint;
	c : char;
	w : array[0..24,0..79] of char;
begin
	readln(n);
	fillchar(w,sizeof(w),' ');
	for ni := 1 to n do begin
		readln(c, x1,y1,x2,y2 );
		for i := x1 to x2 do begin
			w[y1,i] := c;
			w[y2,i] := c;
		end;
		for i := y1 to y2 do begin
			w[i,x1] := c;
			w[i,x2] := c;
		end;
		for i := x1+1 to x2-1 do begin
			for j := y1+1 to y2-1 do begin
				w[j,i] := ' ';
			end;
		end;
	end;
	for i := 0 to 24 do begin
		for j := 0 to 79 do write(w[i,j]);
		writeln;
	end;
end.
