program celeb;
{ Solves the CELEBRITY problem }
var
	i,j : longint;
	r : longint;
begin
	readln(i);
	j := i-1;
	while not ((i <= 0) or (j <= 0)) do begin
		writeln('Q ', i, ' ', j);
		readln(r);
		if r = 1 then i := i - 2 else j := j - 2;
		
		if i < 0 then i := j - 2;
		if j < 0 then j := i - 2;
		writeln('now i = ', i, ' j = ' , j );
	end;
	if i <= 0 then writeln('A ', j);
	if j <= 0 then writeln('A ', i);
end.
