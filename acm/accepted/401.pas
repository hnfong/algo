program p401;
{ @JUDGE_ID:  20044WC 401 PASCAL }
var
	i,l : longint;
	m : array['0'..'Z', '0'..'Z'] of boolean;
	s : string;
	pal, mir : boolean;
begin
	fillchar(m,sizeof(m), false);

	m['A','A'] := true;
	m['E','3'] := true;
	m['H','H'] := true;
	m['I','I'] := true;
	m['J','L'] := true;
	m['L','J'] := true;
	m['M','M'] := true;
	m['O','O'] := true;
	m['S','2'] := true;
	m['T','T'] := true;
	m['U','U'] := true;
	m['V','V'] := true;
	m['W','W'] := true;
	m['X','X'] := true;
	m['Y','Y'] := true;
	m['Z','5'] := true;
	m['1','1'] := true;
	m['2','S'] := true;
	m['3','E'] := true;
	m['5','Z'] := true;
	m['8','8'] := true;
	
	while not eof do begin
		pal := true;
		mir := true;
		readln(s);
		l := length(s);

		{pal}
		for i := 1 to (l div 2) do begin if s[i] <> s[l-i+1] then pal := false; end;

		{mir}
		for i := 1 to (l div 2) do begin if not m[s[i], s[l-i+1]] then mir := false; end;
		if ((l mod 2) = 1) and (m[s[l div 2 + 1], s[l div 2 + 1]] = false) then mir := false;

		if (pal = false) and (mir = false) then writeln(s, ' -- is not a palindrome.');
		if (pal = true) and (mir = false) then writeln(s, ' -- is a regular palindrome.');
		if (pal = false) and (mir = true) then writeln(s, ' -- is a mirrored string.');
		if (pal = true) and (mir = true) then writeln(s, ' -- is a mirrored palindrome.');
		writeln;
	end;
end.
