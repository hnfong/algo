program acm111;
{
	@JUDGE_ID:  20044WC 111 PASCAL "Siliconism"
}
var
	dp : array [0..20, 0..20] of longint;
	n : longint;
	i,j,k : longint;
	a, b : array[0..20] of longint;
	t : longint;
procedure dump;
var i,j : longint;
begin
	for i := 1 to n do write(a[i], ' '); writeln;
	for i := 1 to n do write(b[i], ' '); writeln;
	for i := 1 to n do begin
		for j := 1 to n do
			write(dp[i,j]:1, ' ');
		writeln;
	end;
end;

function lcs(x,y:longint) : longint;
label exitplace;
begin
	if (x < 0) or (y < 0) then begin lcs := 0; exit; end;
	if (dp[x,y] >= 0) then goto exitplace;

	if (x = 0) or (y = 0) then begin
		dp[x,y] := 0;
		goto exitplace;
	end;
	if (a[x] = b[y]) then begin
		dp[x,y] := lcs(x-1,y-1) + 1;
		goto exitplace;
	end;
	if lcs(x-1,y) > lcs(x,y-1) then dp[x,y] := lcs(x-1,y) else dp[x,y] := lcs(x, y-1);
	exitplace:
	lcs := dp[x,y];
end;

begin
	fillchar(a, sizeof(a), 0);
	fillchar(dp, sizeof(dp), 255);
	fillchar(b, sizeof(b), 0);
	readln(n);
	for i := 1 to n do begin read(t); a[t] := i; end; readln;
	for i := 1 to n do begin read(t); b[t] := i; end; readln;
	writeln(lcs(n, n));
end.

