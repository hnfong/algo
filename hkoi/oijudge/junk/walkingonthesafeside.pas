program wotss;
var
	i,j,k,w,n,a :longint;
	dp : array[0..200,0..200] of longint;
procedure setdp(a,b,v:longint);
begin
	if dp[a,b] >= 0 then dp[a,b] := v;
end;
function getdp(a,b:longint):longint;
begin
	if dp[a,b] = -1 then getdp := 0 else getdp := dp[a,b];
end;

begin
	fillchar(w,sizeof(w),w);
	readln(w,n);
	for i := 1 to w do begin
		read(k);
		while not eoln do begin
			read(a);
			dp[k,a] := -1;
		end;
		readln;
	end;
	for j := 1 to n do begin
		setdp(1,1,1);
	end;
	for i := 1 to w do begin
		for j := 1 to n do begin
			if (i=1) and (j=1) then continue;
			setdp(i,j, getdp(i,j-1)+getdp(i-1,j));
		end;
	end;
	writeln(getdp(w,n));
end.
