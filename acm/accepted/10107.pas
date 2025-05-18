program p10107;
{
	@JUDGE_ID: 20044WC 10107 PASCAL "Two Heaps"
}
type
	heap = array[0..50000] of longint; { 0 is the length }
var
	l : heap;
	r : heap;
	i,j,k,n,m: longint;
	v : longint;
function compare(a,b,op : longint) : boolean;
begin
	if op = 1 then compare := a > b;
	if op = 2 then compare := b > a;
end;

procedure heapadd(var h : heap; v,op : longint);
var
	i : longint;
begin
	inc(h[0]);
	i := h[0];
	h[i] := v;
	while (i > 1) and ( compare(v,h[i div 2],op) ) do begin
		h[i] := h[i div 2];
		i := i div 2;
	end;
	h[i] := v;
end;

function heappop(var h : heap; op : longint) : longint;
var
	r,t,l,i : longint;
begin
	r := h[1];
	h[1] := h[h[0]];
	dec(h[0]);
	i := 1;
	while true do begin
		if i * 2 > h[0] then break;
		if compare(h[i], h[i*2], op) and ((i*2+1) > h[0]) then break;
		if compare(h[i], h[i*2], op) and compare(h[i], h[i*2+1],op) then break;
		if (i*2+1) > h[0] then l := i * 2 else begin
			if compare(h[i*2+1], h[i*2],op) then l := i*2+1 else l := i*2;
		end;
		t := h[l];
		h[l] := h[i];
		h[i] := t;

		i := l;
	end;
	heappop := r;
end;

begin
	{ initialize }
	l[0] := 0;
	r[0] := 0;
	n := 1; readln(v); m := v;
	writeln(m);
	while not eof do begin
		inc(n);
		readln(v);
		if v >= m then heapadd(r, v, 2);
		if v < m then heapadd(l, v, 1);
		while l[0] > r[0] do begin
			heapadd(r,m, 2);
			m := heappop(l, 1);
		end;
		while r[0]-1 > l[0] do begin
			heapadd(l,m, 1);
			m := heappop(r, 2);
		end;
		if n mod 2 = 1 then writeln(m);
		if n mod 2 = 0 then writeln(  m div 2 + r[1] div 2 + (m mod 2 + r[1] mod 2) div 2 ) ;
	end;
end.

