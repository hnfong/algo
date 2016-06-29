program p452;
const hc : array[0..9] of string[7] = (
'YYYYYYN',
'NYYNNNN',
'YYNYYNY',
'YYYYNNY',
'NYYNNYY',
'YNYYNYY',
'YNYYYYY',
'YYYNNNN',
'YYYYYYY',
'YYYYNYY'
);
{
YNYYYYN
YNYYNYN
NYYNYYN
}
var
	i,j,k,n:longint;
	s : string[7];
	a : array[1..10] of string[7];
	q : boolean;
	dp : array[0..9,1..1024] of longint;

function match(s:string[7];x:longint):longint;var i,z :longint;
begin
	z := 1;
	for i := 1 to 7 do begin
		if (s[i]='N') and (hc[x][i]='Y') then begin
			z := z + power(2,i);
		end;
		if (s[i]='Y') and (hc[x][i]='N') then begin
			match := 0;
			exit;
		end;
	end;
	match := z;
end;

begin
	while true do begin
		readln(n);
		if n = 0 then break;
		for i := 1 to n do begin
			readln(a[i]);
		end;

		for i := 1 to n do begin
			q := false;
			for j := 9 downto 0 do begin
				if match(a[i],j) > 0 then begin
					q := true;
					writeln(a[i],' ',hc[j], ' ', j);
					break;
				end;
			end;
			if (q = false) then begin
				writeln('MISMATCH');
				break;
			end;
		end;
		if (q = true) then writeln('MATCH');
	end;
end.
