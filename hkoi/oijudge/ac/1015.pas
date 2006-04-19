program p1015;
label fsck;
var
	i,j,k : longint;
	s : array[1..25000] of char;
	p : longint;
	c : char;
begin
	p := 0;
	while not eof do begin
		read(c);
		if (c = '(') or (c = '[') or (c = '{') then begin
			inc(p);
			s[p] := c;
		end;

		if (c = ')') or (c = ']') or (c = '}') then begin
			if (c = ')') then begin
				if s[p] <> '(' then goto fsck;
			end;
			if (c = ']') then begin
				if s[p] <> '[' then goto fsck;
			end;
			if (c = '}') then begin
				if s[p] <> '{' then goto fsck;
			end;
			dec(p);
		end;
	end;
	if p <> 0 then goto fsck;
	writeln('Yes');
	exit;
	fsck:
	writeln('No');
end.

