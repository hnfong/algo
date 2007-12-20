program test;
var
	w : array[0..10000] of longint;
	i,n,k : longint;
	a : double;
begin
	fillchar(w,sizeof(w),0);
	readln(n);
	for i := 1 to n do begin
		readln(a);
		k := round(a * 100);
		inc(w[k]);
	end;
	k := 0;
	for i := 0 to 10000 do begin;
		if w[i] > k then k := w[i];
	end;
	for i := 0 to 10000 do begin
		if (w[i] = k) then writeln(i/100:6:2);
	end;
end.
