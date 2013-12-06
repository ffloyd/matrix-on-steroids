#ifndef MF_MATRIX_OPERATIONS
#define MF_MATRIX_OPERATIONS

namespace matrix_operation
{
	template<class number, class LeftOp, class RightOp>
	struct plus
	{
		const LeftOp&  left;
		const RightOp& right;
		int N, M;

		plus(const LeftOp& left, const RightOp& right, const int N, const int M) :
			left(left),
			right(right),
			N(N),
			M(M)
		{}

		const number get(const int i, const int j) const
		{
			return left.get(i, j) + right.get(i, j);
		}

		template<class LocalRightOp>
		plus< number, plus<number, LeftOp, RightOp>, LocalRightOp > operator+(const LocalRightOp& local_right)
		{
			return plus< number, plus<number, LeftOp, RightOp>, LocalRightOp >(*this, local_right, N, M);
		}
	};
}
#endif
