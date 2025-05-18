program p1038;
var
	a,b,i,j,k,n,r : longint;
	w : array[1..100,1..100] of longint;
	ans : array[1..100] of longint;
	asdf : longint;
procedure dfs(x:longint);
var i,j : longint;
begin
	inc(asdf);
	ans[asdf] := x;
	for i := 1 to n do begin
		if w[x,i]=1 then begin
			w[x,i] := 0;
			w[i,x] := 0;
			dfs(i);
		end;
	end;
end;
begin
	asdf := 0;
	fillchar(w,sizeof(w),0);
	readln(n);
	readln(r);
	for i := 1 to n-1 do begin
		readln(a,b);
		w[a,b] := 1;
		w[b,a] := 1;
	end;
	dfs(r);
	for i := 1 to asdf-1 do write(ans[i], ' '); writeln(ans[asdf]);
end.
