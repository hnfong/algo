program p10405;
{
	@JUDGE_ID: 20044WC 10405 PASCAL "DyP/LCS"
}
var
	i,j,k : longint;
	dp : array[1..1000,1..1000] of longint;
	s1,s2 : array[1..1000] of char;
	ls1,ls2 : longint;
function max(a,b: longint) : longint;
begin
	if a > b then max := a else max := b;
end;

function lcs(a,b:longint) : longint;
begin
	if (a <= 0) or (b <= 0) or (a > ls1) or (b > ls2) then begin lcs := 0; exit; end;
	if dp[a,b] >= 0 then begin
		lcs := dp[a,b];
		exit;
	end;
	if s1[a] = s2[b] then begin
		dp[a,b] := 1 + lcs(a+1,b+1);
	end else begin
		dp[a,b] := max(lcs(a+1,b),lcs(a,b+1));
	end;
	lcs := dp[a,b];
end;
begin
	while not eof do begin
	fillchar(dp,sizeof(dp),255);
	ls1 := 0;
	while not eoln do begin
		inc(ls1);
		read(s1[ls1]);
	end;
	readln;
	ls2 := 0;
	while not eoln do begin
		inc(ls2);
		read(s2[ls2]);
	end;
	readln;
	writeln(lcs(1,1));
	end;
end.

