program pstamp;
const
	h : array[1..17] of longint = (
		1,2,3,4,8,10,13,20,25,31,40,50,100,200,240,480,500
	);
	debug = false;
var
	i,j,k,e,n,m,z : longint;
	w : array[0..20000] of longint;
	v : array[0..20000] of longint;
	l : array[0..20000] of longint;
	c : array[0..30] of longint;
	n2 : longint;
begin
	fillchar(w,sizeof(w),0);
	fillchar(v,sizeof(v),0);
	fillchar(l,sizeof(l),0);
	{ find the minimum number of stamps to get to the value }
	for i := 1 to 20000 do begin
		e := 100000;
		k := 0;
		for j := 1 to 17 do begin
			if i - h[j] < 0 then continue;
			if w[i-h[j]]+1 < e then begin
				e := w[i-h[j]]+1;
			end;
		end;
		w[i]:=e;
	end;
	{ find the sums of each subset of the given stamps }
	{ and record the minimum number of stamps req. to make up the value }
	if debug then writeln('!!!!DONE!!!!');
	
	readln(m);
	readln(n);
	for i := 1 to n do begin
		readln(c[i]);
	end;
	
	if debug then writeln('done');
	for i := 1 to n do begin
		z := 0;
		for j := n2 downto 0 do begin
			k := l[j]+c[i];
			if (k<=40000) then begin
				if (v[l[j]]+1 < v[k]) or (v[k] = 0) then begin
					v[k]:=v[l[j]]+1;
					inc (z);
					l[n2+z]:=k;
				end;
			end;
		end;
		n2 := n2 + z;
	end;
	if debug then begin
		for i := 1 to n2 do begin
			write(l[i],' ');
		end;writeln;
		for i := 1 to n2 do begin
			write(v[l[i]],' ');
		end;writeln;
	end;

	{ DONE 2 };
	if debug then writeln('done 2');

	e := 999999;
	for i := n2 downto 0 do begin
		{ if optimal }
		if (m-l[i] >= 0) and (v[l[i]] + w[m-l[i]] = w[m]) then begin
			{ if less than current min }
			if w[m-l[i]] < e then begin
				{ register this }
				e := w[m-l[i]];
			end;
		end;
	end;
	writeln(e);
end.

