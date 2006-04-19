program trivial;
var
	i,j,k : longint;
	n : longint;
	m : longint;
	a : array[1..1000] of longint;
	sum,mindif : longint;
begin
	readln(n);
	for k := 1 to n do begin
		fillchar(a, sizeof(a), 0);
		read(m);
		sum := 0;
		for i := 1 to m do begin
			read(a[i]);
		end;
		readln;
		for i := 1 to m-1 do begin
			for j := i downto  1 do begin
				if a[j] > a[j+1] then begin
					k := a[j];
					a[j] := a[j+1];
					a[j+1 ] := k;
				end;
			end;
		end;
		mindif := 0;
		for i := 1 to m do begin
			mindif := abs(mindif - a[i]);
		end;
		writeln(mindif);
	end;
end.
