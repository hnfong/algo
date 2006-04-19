program dia;
var
	i,j : longint;
begin
	for i := 1 to 10 do begin
		for j := 0 to i-1 do begin
			write(10-i+j,' ', j, '  ');
		end;writeln;
	end;
end.
