program p1039;
type
	asdf = array[1..200000,1..2] of longint;
var
	i,j,k,r,n : longint;
	w,tmp : asdf;
	first : boolean;
	ind : array[1..100001] of longint;
	v : array[1..100000] of boolean;
procedure csort(var x:asdf; d:longint);
var i : longint;
cs : array[1..100000] of longint;
begin
	fillchar(cs,sizeof(cs),0);
	for i := 1 to 2*(n-1) do begin
		inc(cs[x[i,d]]);
	end;
	for i := 2 to 100000 do begin
		ind[i] := cs[i-1]+1;
		cs[i] := cs[i]+cs[i-1];
	end;
	ind[n+1] := n;
	for i := 2*(n-1) downto 1 do begin
		tmp[cs[x[i,d]]] := x[i];
		dec(cs[x[i,d]]);
	end;
	x := tmp;
end;
procedure dfs(x: longint);
var i : longint;
begin
	if v[x] then exit;
	v[x] := true;
	for i := ind[x] to ind[x+1]-1 do begin
		dfs(w[i,2]);
	end;
	if first then write(x) else  write(' ', x);
	first := false;
end;
begin
	fillchar(w,sizeof(w),0);
	fillchar(v,sizeof(v),0);
	fillchar(ind,sizeof(ind),0);
	fillchar(tmp,sizeof(tmp),0);
	first:=true;
	readln(n);
	readln(r);
	ind[1] := 1;
	for i := 1 to n - 1 do begin
		readln(w[i,1],w[i,2]);
		w[i+n-1,1] := w[i,2];
		w[i+n-1,2] := w[i,1];
	end;
	csort(w,2);
	csort(w,1);
	dfs(r);
	writeln;
end.
