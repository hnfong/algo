program triangle;
var
	orig : array[0..101,0..101] of integer;
	dp : array[0..101,0..101] of integer;
	i,j,k : longint;
	n : longint;
begin
	readln(n);
	fillchar(orig, sizeof(orig), 0);
	for i := 1 to n do begin
		for j := 1 to i do begin
			read(orig[i,j]);
		end;
		readln;
	end;
	fillchar(dp, sizeof(dp), 0);
	for i := 1 to n do begin
		for j := 1 to n do begin
			if dp[i-1,j] > dp[i-1,j-1] then dp[i,j] := dp[i-1,j] + orig[i,j] else dp[i,j] := dp[i-1,j-1] + orig[i,j];
		end;
	end;
	k := 0;
	for i := 1 to n do begin
		if dp[n,i] > k then k := dp[n,i];
	end;
	writeln(k);
end.
