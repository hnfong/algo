program p10397;

{
@JUDGE_ID: 20044WC 10397 PASCAL
}

const debug = false;
type edge = record
	l : double;
	e : array[1..2] of longint;
end;

var
	t : edge;
	a,b,i,j,k,m,n,mi,r,nu : longint;
	w : array[1..750] of longint; { set it belongs to }
	x : array[1..750] of longint; { x }
	y : array[1..750] of longint; { y }
	v : array[1..750*750] of edge; {edges}
	u : array[1..750,1..2] of longint;
	total : double;

procedure join(a,b:longint);
var i,f,e : longint;
begin
	if w[a]=w[b] then exit;
	if w[a]>w[b] then begin
		f := w[a];
		e := w[b];
	end else begin
		f := w[b];
		e := w[a];
	end;
	for i := 1 to m do begin if w[i]=f then w[i] := e; end;
	inc(nu);
	u[nu,1] := a;
	u[nu,2] := b;
	total := total + sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
	if debug then begin
		for i := 1 to m do write(i,' '); writeln;
		for i := 1 to m do write(w[i],' '); writeln;
		writeln(total:0:3);
	end;
end;
procedure cxqsort(p,r : longint);
var
   m,t : edge;
   i,j : longint;
begin
   i := p; j := r; m := v[(i+j) div 2];
   repeat
      while (v[i].l < m.l) do inc(i);
      while (m.l < v[j].l) do dec(j);
      if (i <= j) then
      begin
         t := v[i]; v[i] := v[j]; v[j] := t;
        inc(i); dec(j);
      end;
   until (i > j);
   if (p < j) then cxqsort(p,j);
   if (i < r) then cxqsort(i,r);
end;

begin
	while not eof do begin
		while not eof and eoln do readln;
		if eof then break;
		readln(m);
		n := 0; nu := 0;
		total := 0;
		for i := 1 to m do begin
			w[i] := i;
			readln(x[i],y[i]);
			for j := 1 to i - 1 do begin
				inc(n);
				v[n].l := sqrt(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
				v[n].e[1] := i;
				v[n].e[2] := j;
			end;
		end;
		
		{
		k := n;
		while k > 1 do begin
			k := k div 3 + 1;
			for i := 2 to n do begin
				j := i;
				t := v[i];
				while (j>k) and (t.l<v[j-k].l) do begin
					v[j] := v[j-k];
					dec(j,k);
				end;
				v[j] := t;
			end;
		end;
		}
		cxqsort(1,n);
		for i := 2 to n do if v[i].l < v[i-1].l then while true do;
		readln(r);
		for i := 1 to r do begin
			readln(a,b);
			join(a,b);
			total := total - sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b]));
		end;
		for i := 1 to n do begin
			if debug then writeln(v[i].l:0:2);
			join(v[i].e[1], v[i].e[2]);
		end;
		writeln(total:0:2);
		{ end of testcase }
	end;
end.
