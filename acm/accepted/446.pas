program p446;
{
	@JUDGE_ID: 20044WC 446 PASCAL "DaP/DyP"
}
var
	i,j,k : longint;
	a,b : string[100];
	n : longint;
	ni : longint;
	c : char;
	s1,s2,s3 : string[10];
	z : longint;

function alphanumeric(c:char):boolean;
begin
	alphanumeric := false;
	if (c>='0') and (c<='9') then alphanumeric := true;
	if (c>='A') and (c<='F') then alphanumeric := true;
	if (c = '+') or (c= '-') then alphanumeric := true;
end;

function h2b(c:char):string[4];
const
	hc1 : array['0'..'9'] of string[4] = ( '0000', '0001', '0010', '0011', '0100', '0101', '0110', '0111', '1000', '1001');
	hc2 : array['A'..'F'] of string[4] = ( '1010', '1011', '1100', '1101', '1110', '1111');
begin
	if c <= '9' then h2b := hc1[c] else h2b := hc2[c];
end;

begin
	readln(n);
	for ni := 1 to n do begin
		s1 := '';s2 := '';s3 := ''; a := ''; b := '';
		while true do begin
			read(c);
			if not alphanumeric(c) then break;
			s1 := s1 + c;
		end;
		while true do begin
			read(c);
			if not alphanumeric(c) then break;
			s2 := s2 + c;
		end;
		while true do begin
			read(c);
			if not alphanumeric(c) then break;
			s3 := s3 + c;
		end;
		for i := 1 to length(s1) do begin a := a+h2b(s1[i]); end;
		for i := 1 to length(s3) do begin b := b+h2b(s3[i]); end;
		a := copy('0000000000000', 1, (4*3+1-length(a))) + a;
		b := copy('0000000000000', 1, (4*3+1-length(b))) + b;
		z := 0;
		for i := 13 downto 2 do begin
			z := z + (ord(a[i])-48) * power(2,13-i);
			if s2 = '+' then z := z + (ord(b[i])-48) * power(2,13-i);
			if s2 = '-' then z := z - (ord(b[i])-48) * power(2,13-i);
		end;
		writeln(a, ' ', s2 , ' ', b, ' = ', z);
	end;
end.
