var
	i,j,k,n,z : longint;
	dp : array[0..1,0..1,1..100] of longint;
	w : array[1..33] of longint;
function d(a,b,n : longint) : longint;
begin
	if (dp[a,b,n] <> -1) then begin
		d := dp[a,b,n];
		exit;
	end;
	if (a=0)and(b=0) then dp[a,b,n] := d(1,0,n-1) + d(0,0,n-1);
	if (a=0)and(b=1) then dp[a,b,n] := d(1,1,n-1) + d(0,1,n-1);
	if (a=1)and(b=0) then dp[a,b,n] := d(0,0,n-1);
	if (a=1)and(b=1) then dp[a,b,n] := d(0,1,n-1);
	d:=dp[a,b,n];
end;

begin
	for i := 1 to 100 do begin
	dp[0,0,i] := -1;
	dp[0,1,i] := -1;
	dp[1,0,i] := -1;
	dp[1,1,i] := -1;
	end;
	dp[0,0,1] := 1;
	dp[0,1,1] := 0;
	dp[1,0,1] := 0;
	dp[1,1,1] := 1;
	readln(n);
	z := 0;
	k := 0;
	while n > 0 do begin
		inc(k);
		w[k] := n mod 2;
		n := n div 2;
	end;
	n := k;
	
	{for i := 1 to n div 2 do begin
		k := w[i];
		w[i] := w[n-i];
		w[n-i] := k;
	end;}

	{ check whether it is valid seq }
	for i := 2 to n do begin
		if (w[i] = 1) and (w[i-1] = 1) then begin
			writeln(0);
			exit;
		end;
	end;

	z := 0;

	for i := 1 to n do begin
		if (w[i] = 1) then z := z + d(0,0,i)+d(0,1,i);
	end;
	
	writeln(z);
end.


