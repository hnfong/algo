program p3;
const	
	m : array['a'..'c', 'a'..'c'] of char = (
		('b','b','a'),
		('c','b','a'),
		('a','c','c')
	);
var
	i,j,k : longint;
	dp : array[1..50, 'a'..'c'] of boolean;
	h : array[1..3] of char;
	t : char;
	l : longint;
	s : string;

procedure dump;
begin
	exit;
	writeln(t);
	writeln(s);
	for i := 1 to l do begin if dp[i,'a'] then write('T') else write('F'); end; writeln;
	for i := 1 to l do begin if dp[i,'b'] then write('T') else write('F'); end; writeln;
	for i := 1 to l do begin if dp[i,'c'] then write('T') else write('F'); end; writeln;
end;

begin
	h[1] := 'a';
	h[2] := 'b';
	h[3] := 'c';
	fillchar(dp, sizeof(dp), 0);
	readln(t);
	readln(s);
	l := length(s);
	dp[l,s[l]] := true;
	if l > 1 then dp[l-1, m[s[l-1],s[l]]] := true;
	if l > 2 then
	for i := l - 2 downto 1 do begin
		for j := 1 to 3 do begin
			if dp[i+1,h[j]] then begin
				dp[i, m[s[i],h[j]]] := true;
			end;
			if dp[i+2, h[j]] then begin
				dp[i, m[m[s[i],s[i+1]], h[j]]] := true;
			end;
		end;
	end;
	dump;
	if dp[1,t] then writeln('yes') else writeln('no');
end.
