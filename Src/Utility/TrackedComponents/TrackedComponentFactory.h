#pragma once

#include "Interfaces/IModel/IModelTrackedComponentFactory.h"

class TrackedComponentFactory : public IModelTrackedComponentFactory
{
    Q_OBJECT
public:
    TrackedComponentFactory();
    virtual ~TrackedComponentFactory();

    virtual QList<QString> getElementTypes() override;
    // ITrackedComponentFactory interface
protected:
    virtual IModelTrackedComponent* createTrackedElement(
        QString name) override;
    virtual IModelTrackedComponent* createTrackedObject(QString name) override;
    virtual IModelTrackedComponent* createTrackedTrajectory(
        QString name) override;
};
