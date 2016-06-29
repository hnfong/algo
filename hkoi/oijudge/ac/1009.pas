program p1009;
var
	c : char;
begin
	while not eof do begin
		read(c);
		if (c >= 'A') and (c <= 'Z') then write(c);
		if (c >= 'a') and (c <= 'z') then write(c);
		if (c = ' ') or (ord(c) = 13) or (ord(c) = 10) then write(c);
	end;
end.
