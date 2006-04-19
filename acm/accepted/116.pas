program p116;
{
	@JUDGE_ID:  20044WC 116 PASCAL "DaP/DyP"
}
type xxx = array[1..3] of longint;
var
	i,j,k : longint;
	dp : array[1..100,1..100] of longint;
	n,m : longint;
	e : longint;
	s : xxx;
	min : longint;
function nex (x : longint) : longint; var t : longint; begin
	t := (x+1) mod m;
	if t = 0 then t := m;
	nex := t;
end;
function pre (x : longint) : longint; var t : longint; begin
	t := (m+x-1) mod m;
	if t = 0 then t := m;
	pre := t;
end;

function sort3(a,b,c:longint) : xxx;
var i,j,k : longint; x : xxx;
begin
	x[1] := a; x[2] := b; x[3] := c;
	for i := 1 to 3 do begin
		for j := i downto 2 do begin
			if x[j] < x[j-1] then begin
				k := x[j];
				x[j] := x[j-1];
				x[j-1] := k;
			end;
		end;
	end;
	sort3 := x;
end;

function minof3(a,b,c:longint) : longint;
begin
	if (a<=b) and (a<=c) then minof3 := a;
	if (b<=a) and (b<=c) then minof3 := b;
	if (c<=a) and (c<=b) then minof3 := c;
end;

procedure dump; var i,j : longint;
begin
	for i := 1 to m do begin
		for j := 1 to n do begin
			write(dp[i,j]:3);
		end;
		writeln;
	end;
	writeln;
end;

begin
	while not eof do begin
		fillchar(dp,sizeof(dp),0);
		readln(m,n);
		for i := 1 to m do begin
			for j := 1 to n do begin
				read(dp[i,j]);
			end;
		end;
		{ dp }
		for i := n-1 downto 1 do begin
			for j := 1 to m do begin
				dp[j,i] := dp[j,i] + minof3(dp[nex(j),i+1], dp[j,i+1], dp[pre(j),i+1]);
			end;
		end;
		{ backtrack }
		e := 10000000; { infinity }
		k := 1;
		for i := 1 to m do begin
			if dp[i,1] < e then begin
				e := dp[i,1];
				k := i;
			end;
		end;
		min := e;
		write(k);
		for i := 1 to n-1 do begin
			e := minof3(dp[nex(k),i+1], dp[k,i+1], dp[pre(k),i+1]);
			s := sort3(nex(k),k,pre(k));
			for j := 1 to 3 do begin
				if dp[s[j],i+1] = e then begin
					k := s[j];
					write(' ',k);
					break;
				end;
			end;
		end;
		writeln;
		writeln(min);
		readln;
	end;
end.
