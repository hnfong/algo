program reverse;
{ reverses the input (MO LIU) }
var
	a : array[1..10000] of char;
	c : char;
	i,l : integer;
begin
	while not eof do begin
		l := 0;
		while not eoln do begin
			read(c);
			if (l > 100000) then break;
			inc(l);
			a[l] := c;
		end;
		readln;
		for i := 1 to (l div 2) do begin
			c := a[i];
			a[i] := a[l-i+1];
			a[l-i+1] := c;
		end;
		for i := 1 to l do begin
			write(a[i]);
		end;writeln;
	end;
end.
