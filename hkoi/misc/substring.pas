program test;
var
	s : string;
	b : string;
	i,k : integer;
	q : boolean;
	f : text;
begin
	readln(b);
	assign(f, '/usr/share/dict/words');
	reset(f);
	while not eof(f) do begin
		readln(f,s);
		k := 1;
		for i := 1 to length(s) do begin
			if s[i] = b[k] then begin
				inc(k);
			end;
		end;
		if k > length(b) then writeln(s);
	end;
	close(f);
end.
