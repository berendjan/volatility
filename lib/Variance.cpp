#include <array>

namespace volatility
{

/// Welford's Algorithm adapted for circular buffer
class StreamingSlidingWindowVolatility
{

    static constexpr auto NUM_POINTS = 4320;

public:
    void add_point(float price, int timestamp)
    {
        timestamp %= NUM_POINTS;

        auto is_filled = filled == NUM_POINTS;

        float old_price = buffer[timestamp];
        buffer[timestamp] = price;
        sum_points += price - old_price;
        filled += static_cast<int>(!is_filled);
        double mean = sum_points / filled;
        var_sum += (price - old_mean) * (price - mean) -
                   static_cast<double>(is_filled) * (old_price - old_mean) *
                       (old_price - mean);
        old_mean = mean;
    }

    float get_volatility()
    {
        return var_sum / filled; //
    }

private:
    std::array<float, NUM_POINTS> buffer{};
    double sum_points = 0;
    double var_sum = 0;
    double old_mean = 0;
    int filled = 0;
};

} // namespace volatility