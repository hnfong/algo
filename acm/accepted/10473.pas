program p10473;
{
	@JUDGE_ID: 20044WC 10473 PASCAL
}
const
	h2 : array[0..15] of char = (
	'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'
	);
var
	i,j,k,z : longint;
	hc : array['0'..'F'] of byte;
	s : string;
	c : char;
	startwriting : boolean;
begin
	hc['0'] := 0; hc['1'] := 1; hc['2'] := 2; hc['3'] := 3;
	hc['4'] := 4; hc['5'] := 5; hc['6'] := 6; hc['7'] := 7;
	hc['8'] := 8; hc['9'] := 9; hc['A'] := 10; hc['B'] := 11;
	hc['C'] := 12; hc['D'] := 13; hc['E'] := 14; hc['F'] := 15;
	while true do begin
		readln(s);
		if (s[1]='-') then break;
		if (s[1]='0') and (s[2]='x') then begin
			{ hex }
			z := 0;
			delete(s,1,2);
			for i := 1 to length(s) div 2 do begin
				c := s[i];
				s[i] := s[length(s)-i+1];
				s[length(s)-i+1] := c;
			end;
			for i := 1 to length(s) do begin
				z := z + hc[s[i]] shl ((i-1)*4);
			end;
			writeln(z);
		end else begin
			z := 0;
			for i := 1 to length(s) do begin
				z := z * 10;
				z := z + ord(s[i])-48;
			end;
			s := '';
			write('0x');
			startwriting := false;
			for i := 7 downto 0 do begin
				if (h2[(z shr (i*4)) and 15]) > '0' then startwriting := true;
				if startwriting then write(h2[(z shr (i*4)) and 15]);
			end;
			writeln;
		end;
	end;
end.
