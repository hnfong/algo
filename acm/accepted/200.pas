program acm200;
{ @JUDGE_ID:  20044WC 200 PASCAL "Siliconism" }
{ Topological Sort }
var
	i,k : longint;
	s : array[0..1] of string;
	a : array['A'..'Z', 'A'..'Z'] of boolean;
	z,p : byte;
	t : boolean;
	c,d : char;
	f : longint;
	u : array['A'..'Z'] of boolean;
	nu : longint;

procedure dump;
var	c,d  : char;
begin
	for c := 'A' to 'Z' do if u[c] then write(c); writeln;
	write(' ':3);
	for c := 'A' to 'Z' do write(c:3); writeln;
	for c := 'A' to 'Z' do begin
		write(c:3);
		for d := 'A' to 'Z' do begin
			if a[c,d] then write('1':3) else write('0':3);
		end;writeln;
	end;
end;

begin
	while not eof do begin
	{ k, s, p, t, c, d }
	fillchar(a,sizeof(a),0);
	fillchar(u,sizeof(u),0);
	nu := 0;
	f := 0;
	z := 0;
	readln(s[z]);
	for i := 1 to length(s[z]) do begin u[s[z,i]] := true; end;

	while true do begin
		p := z;
		z := (z+1) mod 2;
		readln(s[z]);
		if s[z] = '#' then break;
		for i := 1 to length(s[z]) do begin u[s[z,i]] := true; end;
		k := 1;
		while s[0,k] = s[1,k] do inc(k);
		if (ord(s[p,k]) < 65) or (ord(s[z,k]) < 65) then continue;
		a[s[p,k], s[z,k]] := true;
	end;
	for c := 'A' to 'Z' do if u[c] then inc(nu);

	{dump;}
	{tsort}
	while f < nu do begin
		for c := 'A' to 'Z' do begin
			if not u[c] then continue;
			t := false;
			for d := 'A' to 'Z' do begin
				if a[d,c] then t := true;
			end;
			if t = false then begin
				u[c] := false;
				write(c);
				inc (f);
				for d := 'A' to 'Z' do begin
					a[c,d] := false;
				end;
			end;
		end;
	end;
	writeln;
	end;
end.
