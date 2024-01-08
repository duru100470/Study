namespace Calculator;

public interface IExpression
{
    int Calculate();
}

public abstract class Operator
{
    protected IExpression augend;
    protected IExpression addend;

    public Operator(IExpression augend, IExpression addend)
    {
        this.augend = augend;
        this.addend = addend;
    }

    public abstract int Calculate();
}

public class Sum : Operator, IExpression
{
    public Sum(IExpression augend, IExpression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend.Calculate() + addend.Calculate();
    }
}

public class Subtract : Operator, IExpression
{
    public Subtract(IExpression augend, IExpression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend.Calculate() - addend.Calculate();
    }
}

public class Multiply : Operator, IExpression
{
    public Multiply(IExpression augend, IExpression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend.Calculate() * addend.Calculate();
    }
}

public class Divide : Operator, IExpression
{
    public Divide(IExpression augend, IExpression addend) : base(augend, addend) { }

    public override int Calculate()
    {
        return augend.Calculate() / addend.Calculate();
    }
}

public class Integer : IExpression
{
    private int number;

    public Integer(int number)
    {
        this.number = number;
    }

    public int Calculate()
    {
        return number;
    }
}