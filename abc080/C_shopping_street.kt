import java.util.*

fun main(args: Array<String>) {
    val sc = Scanner(System.`in`)
    val N = sc.nextInt()
    var F = IntArray(N, {
        (1..10).map { sc.nextInt() }.reduce { acc, i -> acc.shl(1) + i }
    })
    var P = Array(N, { Array(11, { sc.nextInt() }) })
    val max = (1..1023)
            .map { state ->
                F.map { it and state }
                        .map { Integer.bitCount(it) }
                        .mapIndexed { index, count -> P[index][count] }
                        .sum()
            }.max()
    println(max)
}
