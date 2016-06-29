program p147;
{
	@JUDGE_ID:  20044WC 147 PASCAL "Dynamic Programming"
}
const
	hc : array[0..10] of longint = (0,1,2,4,10,20,40,100,200,400,1000); { types of coints }
var
	i,n : longint;
	dp : array[0..1000, 0..10] of longint;
	d : double;

{ recursive DP function, returns the number of combinations for $v with the first n types of coins }
function num(v, n : longint) : longint; 
label quitlabel;
var
	i : longint;
	r : longint;
begin
	r := 0;
	
	{ invalid cases }
	if (v < 0) or (n < 0) then goto quitlabel;
	
	{ cached }
	if dp[v,n] > 0 then begin
		r := dp[v,n];
		goto quitlabel;
	end;
	
	{ base case }
	if (v = 0) or (n = 1) then begin r := 1; goto quitlabel; end;
	
	{ summation of subcases }
	for i := n downto 1 do begin
		r := r + num(v-hc[i], i);
	end;
	
	{ write to dp array and exit }
	quitlabel:
	if (v >= 0) and (n > 0) then dp [v,n] := r;
	num := r;
	exit;
end;

begin
	{ initialize }
	fillchar(dp,sizeof(dp),0);
	
	{preprocess}
	for i := 1 to 1000 do num(i,10);

	{ I/O }
	while not eof do begin
		readln(d);
		if round(d * 100) = 0 then break;
		{ strategy : we make the input to integers before processing them to avoid rounding errors and to simplify the DyP }
		n := round(d * 100) div 5;
		writeln( d:5:2, num(n, 10):12 );
	end;
end.

