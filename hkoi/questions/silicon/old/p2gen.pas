program gen;
var
	i,j,k : longint;
begin
	randomize;
	readln(k);
	for i := 1 to k do begin
		for j := 1 to 10 do begin
			write(chr(random(26)+65));
		end;writeln;
	end;
end.
