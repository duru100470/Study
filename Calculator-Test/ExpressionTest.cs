using Calculator;

namespace Calculator_Test;

public class ExpressionTest
{
    [Test]
    public void Sum_TwoNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression = new Sum(new Integer(1), new Integer(1));
        
        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(2));
    }

    [Test]
    public void Subtract_TwoNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression = new Subtract(new Integer(5), new Integer(2));
        
        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(3));
    }

    [Test]
    public void Multiply_TwoNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression = new Multiply(new Integer(5), new Integer(2));
        
        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(10));
    }

    [Test]
    public void Sum_ThreeNumbers_ReturnValidNumber()
    {
        // Arrange
        IExpression expression1 = new Sum(new Integer(1), new Integer(1));
        IExpression expression2 = new Sum(expression1, new Integer(2));

        // Act
        var ret = expression2.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(4));
    }

    [Test]
    public void Integer_SingleNumber_ReturnsThatNumber()
    {
        // Arrange
        IExpression expression = new Integer(1);

        // Act
        var ret = expression.Calculate();

        // Assert
        Assert.That(ret, Is.EqualTo(1));
    }
}