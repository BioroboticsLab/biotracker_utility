#pragma once

#include "Interfaces/IModel/IModelTrackedTrajectory.h"
#include "QList"
#include "QString"

/**
 * This class inherits from the IModelTrackedTrajectory class and is therefor
 * part of the Composite Pattern. This class represents the Composite class.
 * This class is responsibility for the handling of Leaf objects.
 * Internaly this class uses a QList for storing Leaf object.
 *
 * Objects of this class have a QObject as parent.
 */
class TrackedTrajectory : public IModelTrackedTrajectory
{
    Q_OBJECT

public:
    TrackedTrajectory(QObject* parent = 0, QString name = "n.a.");
    virtual ~TrackedTrajectory(){};

    // ITrackedComponent interface
public:
    void operate() override;

    // ITrackedObject interface
public:
    virtual void add(IModelTrackedComponent* comp, int pos = -1) override;
    virtual bool remove(IModelTrackedComponent* comp) override;
    virtual void clear() override;
    virtual IModelTrackedComponent* getChild(int index) override;
    virtual IModelTrackedComponent* getValidChild(int index) override;
    virtual IModelTrackedComponent* getLastChild() override;

    virtual int size() override;
    virtual int validCount() override;

    virtual QList<IModelTrackedComponent*> getChildNodes() override
    {
        return _TrackedComponents;
    }
    virtual void setChildNodes(QList<IModelTrackedComponent*> n) override
    {
        _TrackedComponents = n;
    }
    virtual bool hasChildNodes() override
    {
        return !_TrackedComponents.empty();
    }

protected:
    QList<IModelTrackedComponent*> _TrackedComponents;

    QString name;
};
