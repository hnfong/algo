program p305hc;
{
	@JUDGE_ID: 20044WC 305 PASCAL " HARDCODE "
}
const	
	hc : array[1..13] of longint = (
2,
7,
5,
30,
169,
441,
1872,
7632,
1740,
93313,
459901,
1358657,
2504881
		
	);
var
	k : longint;
begin
	while true do begin readln(k); if k = 0 then break else writeln(hc[k]); end;
end.
