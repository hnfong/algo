program p20357;
const
	hc : array[1..5] of longint = (1,5,10,25,50);
var
	i,j,k,n,z : Longint;
	dp : array[0..99,1..5] of longint;
begin
	n := 99;
	fillchar(dp,sizeof(dp),0);
	dp[0,1] := 1;
	dp[0,2] := 1;
	dp[0,3] := 1;
	dp[0,4] := 1;
	dp[0,5] := 1;
	for i := 1 to n do begin
		z := 0;
		for j := 1 to 5 do begin
			if i-hc[j]>= 0 then begin
				z := z +dp[i-hc[j],j];
			end;
			dp[i,j] := z;
		end;
	end;

	readln(k);
	if (dp[k,5] = 1) then writeln('There is only 1 way to produce ',k,' cents change.') else
	writeln('There are ',dp[k,5],' ways to produce ', k, ' cents change.');
end.

