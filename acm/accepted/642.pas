program p642;
{
	@JUDGE_ID: 20044WC 642 PASCAL "DaP/DyP"
}
var
	a : array[1..100] of string[8];
	s : string[8];
	b : string[8];
	n : longint;
	i,j,k : longint;
	l : longint;
	found : boolean;
begin
	n := 0;
	while true do begin
		readln(s);
		if s = 'XXXXXX' then break;
		inc(n);
		a[n] := s;
	end;
	for i := 1 to n do begin
		for j := i downto 2 do begin
			if a[j] < a[j-1] then begin
				s := a[j];
				a[j] := a[j-1];
				a[j-1] := s;
			end;
		end;
	end;
	while true do begin
		readln(b);
		if b = 'XXXXXX' then break;
		found := false;
		for i := 1 to n do begin
			if length(a[i]) <> length(b) then continue;
			l := length(b);
			s := b;
			for j := 1 to l do begin
				for k := 1 to l do begin
					if a[i][j] = s[k] then begin
						s[k] := '?';
						break;
					end;
				end;
			end;
			if s = copy('??????',1,l) then begin
				writeln(a[i]);
				found := true;
			end;
		end;
		if not found then writeln('NOT A VALID WORD');
		writeln('******');
	end;
end.
