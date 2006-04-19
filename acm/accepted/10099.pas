program p10099;
{
	@JUDGE_ID: 20044WC 10099 "PASCAL"
}
function min(a,b:longint):longint;
begin if a < b then min:=a else min:=b; end;
var
	i,j,k : longint;
	a,b,c : longint;
	n,r: longint;
	w : array[1..100,1..100] of longint;
	ni : longint;
begin
	ni := 0;
	while true do begin
		inc(ni);
		readln(n,r);
		if (n=0) and (r=0) then break;
		fillchar(w,sizeof(w),0);
		for i := 1 to 100 do w[i,i] := 2147483647;
		 
		for i := 1 to r do begin
			readln(a,b,c);
			w[a,b] := c;
			w[b,a] := c;
		end;
		readln(a,b,c);
		for k := 1 to n do
		for i := 1 to n do
		for j := 1 to n do
		if min(w[i,k],w[k,j]) > w[i,j] then w[i,j] := min(w[i,k],w[k,j]);
		writeln('Scenario #',ni);
		writeln('Minimum Number of Trips = ', (c+w[a,b]-2) div (w[a,b]-1));
		writeln;
	end;
end.
