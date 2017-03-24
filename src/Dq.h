namespace Dq
{
    template <template <typename...> typename Container, typename ...Args>
    class Enumerator
    {
    private:
        Container<Args...> &List;
        typename Container<Args...>::iterator Position = List.begin() - 1;

    public:
        bool MoveNext()
        {
            return ++Position != List.end();
        }

        typename Container<Args...>::value_type &operator*() const
        {
            return *Position;
        }

        void Reset()
        {
            Position = List.begin() - 1;
        }

        typename Container<Args...>::iterator CurrentPostion() const
        {
            return Position;
        }

        typename Container<Args...>::iterator LastPostion() const
        {
            return List.end();
        }

        explicit Enumerator(Container<Args...> &cont) : List(cont)
        {
        }
    };


    template <template <typename...> typename Container, typename ...Args>
    Enumerator<Container, Args...> GetEnumerator(Container<Args...> &cont)
    {
        return Enumerator<Container, Args...>(cont);
    }
}