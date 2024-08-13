while true; do
./data > in.in
./G < in.in > G.out
./G0 < in.in > G0.out
if diff G.out G0.out; then
echo AC
else
echo WA
exit 0
fi
done