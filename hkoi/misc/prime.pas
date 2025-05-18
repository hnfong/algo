program prime;
{ Prints prime numbers from 2 to N (read from stdin) }
var
	i,j,n : longint;
	p : boolean;
begin
	readln(n);
	for i := n downto 2 do begin
		p := true;
		for j := 2 to trunc(sqrt(i)) do begin
			if (i mod j) = 0 then begin
				p := false;
				break;
			end;
		end;
		if p then writeln(i);
	end;
end.
