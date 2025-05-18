program p10338;
{
	@JUDGE_ID:  20044WC 10338 PASCAL "DaP/DyP"
}
var
	k : longint;
	a : array['A'..'Z'] of longint;
	l,n : longint;
	w : int64;
	c : char;

function f(x:longword):int64;var t:int64;i : longint;
begin
	t := 1;
	for i := 1 to x do begin
		t := t * i;
	end;
	f := t;
end;

begin
	readln(n);
	for k := 1 to n do begin
		fillchar(a,sizeof(a),0);
		l := 0;
		while not eoln do begin
			inc(l);
			read(c);
			inc(a[c]);
		end;readln;
		w := f(l);
		for c := 'A' to 'Z' do begin
			w := w div f(a[c]);
		end;
		write('Data set ',k,': ');
		writeln(w);
	end;
end.
