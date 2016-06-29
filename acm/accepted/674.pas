program p674;
{
	@JUDGE_ID: 20044WC 674 PASCAL "DaP/DyP"
}
const
	hc : array [1..5] of longint = ( 1, 5, 10, 25, 50 );
var
	dp : array[0..7489,1..5] of longint;
	i,j,k : longint;
begin
	{ base cases }
	dp[0,1] := 1; dp[0,2] := 1; dp[0,3] := 1; dp[0,4] := 1; dp[0,5] := 1;
	for i := 1 to 5 do begin
		for j := 1 to 7489 do begin
			dp[j,i] := 0;
			for k := 1 to i do begin
				if j-hc[k] >= 0 then dp[j,i] := dp[j,i] + dp[j-hc[k],k];
			end;
		end;
	end;
	while not eof do begin
		readln(i);
		writeln(dp[i,5]);
	end;
end.
