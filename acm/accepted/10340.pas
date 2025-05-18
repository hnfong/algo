program p10340;
{
@JUDGE_ID:  20044WC 10340 PASCAL "DaP/DyP"
}
var
	s1 : array[1..100000] of char;
	l1 : longint;
	i,j,k : longint;
	c : char;
	m : longint;
function alphanumeric(c:char):boolean;
begin
	alphanumeric := false;
	if (c >= 'A') and (c <= 'Z') then alphanumeric := true;
	if (c >= 'a') and (c <= 'z') then alphanumeric := true;
	if (c >= '0') and (c <= '9') then alphanumeric := true;
end;

begin
	while not eof do begin
		fillchar(s1,sizeof(s1),0);
		l1 := 0; m := 0;

		while true do begin
			read(c);
			if not alphanumeric(c) then break;
			inc(l1);
			s1[l1] := c;
		end;

		while not eoln do begin
			read(c);
			if not alphanumeric(c) then continue;
			if s1[m+1] = c then inc(m);
		end; readln;
		if m = l1 then writeln('Yes') else writeln('No');
	end;
end.
