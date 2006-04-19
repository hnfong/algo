program enum;
var
	i,n : longint;
begin
	assign(input,'INPUT.TXT');
	assign(output,'OUTPUT.TXT');
	rewrite(output);
	reset(input);
	readln(n);
	for i := 1 to n*n do begin
		write(i);
		if (i mod n) = 0 then writeln else write(' ');
	end;
	close(input);
	close(output);
end.
