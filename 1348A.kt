import kotlin.math.pow

fun main() {
    val t = readLine()!!.toInt()
    for (x in 0 until t) {
        val n = readLine()!!.toInt()
        println(solve(n));
    }
}

fun solve(n: Int) = (2.0 * (2.0.pow(n / 2) - 1.0)).toInt()
