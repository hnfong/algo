program p1022;
type
	rec = record
		i : longint;
		s : string[10];
	end;
var
	i,j,k,n,t : longint;
	a  : array[1..30000] of rec;
	b : array[1..30000,1..2] of longint;
	s : string;
	w : array[0..65535] of longint;
	e,f : longint;
begin
	fillchar(w,sizeof(w),0);
	fillchar(a,sizeof(a),0);
	fillchar(b,sizeof(b),0);
	readln(n);
	for i := 1 to n do begin
		readln(a[i].s);
		readln(a[i].i);
	end;

	{ shell }
	k := 10000;
	while k > 0 do begin

	for i := 2 to n do begin
		s := a[i].s;
		t := a[i].i;
		j := i;
		while (j > k) and (a[j-k].s < s) do begin
			a[j].s := a[j-k].s;
			a[j].i := a[j-k].i;
			j := j - k;
		end;
		a[j].s := s;
		a[j].i := t;
	end;

	k := k div 3;
	end;

	{ counting }
	for i := 1 to n do inc(w[a[i].i]);
	for i := 1 to 65535 do begin w[i] := w[i-1]+w[i]; end;
	for i := n downto 1 do begin
		b[  w[a[i].i]   , 1 ] := a[i].i;
		b[  w[a[i].i]   , 2 ] := i;
		dec(w[a[i].i]);
	end;
	
	for i := n downto 1 do begin
		writeln(a[b[i,2]].s, ' ', b[i,1]);
	end;
	
end.

