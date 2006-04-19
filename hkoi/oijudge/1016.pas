var 
	i,j,k,n,z,f : longint;
	dp : array[0..100000] of longint;
	v : array[0..100000] of longint;
begin
	readln(n);
	for i := 1 to n do begin
		read(v[i]);
		z := z + v[i];
	end;

	dp[0] := 0;
	for i := 1 to n do begin
		if dp[i-1] > 0 then begin
			dp[i] := dp[i-1] + v[i];
		end else begin
			dp[i] := v[i];
		end;
	end;

	f := 0;
	for i := 1 to n do begin
		if dp[i] > f then f := dp[i];
		v[i] := -v[i];
	end;

	dp[0] := 0;
	for i := 1 to n do begin
		if dp[i-1] > 0 then begin
			dp[i] := dp[i-1] + v[i];
		end else begin
			dp[i] := v[i];
		end;
	end;

	k := 0;
	for i := 1 to n do begin
		if dp[i] > k then k := dp[i];
	end;

	if z+k > f then f := z+k;
	writeln(f);
	
end.
